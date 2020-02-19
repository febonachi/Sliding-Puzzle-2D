#include "gridcontroller.h"

/*ctor*/
GridController::GridController(Item object) : IQmlComponentController(object){

}

/*dtor*/
GridController::~GridController(){
    clear();
}

/*private*/
void GridController::checkIfSolved(){
    QVariantList currentHints;
    for(int row = 0; row < c_gridArray2d.size(); row++){
        for(int col = 0; col < c_gridArray2d.at(row).size(); col++){
            currentHints.append(c_gridArray2d.at(row).at(col)->type());
        }
    }
    if(currentHints == c_hints) emit solved();
}

void GridController::clear(){
    c_hints.clear();

    for(GridArray2d::iterator array = c_gridArray2d.begin(); array != c_gridArray2d.end(); ++array){
        for(GridArray::iterator it = array->begin(); it != array->end(); ++it){
            delete *it; *it = nullptr;
        }
        array->clear();
    }
    c_gridArray2d.clear();

    while(!c_qmlObject->childItems().empty()){
        Item item = c_qmlObject->childItems().takeFirst();
        delete item; item = nullptr;
    }
}

CellController * GridController::createCellController(int size) const{
    Item cell = Game::createQmlObject("CppCell");
    cell->setParent(c_qmlObject);
    cell->setParentItem(c_qmlObject);
    cell->setWidth(size);
    cell->setHeight(size);
    return new CellController(cell);
}

CellController * GridController::atIndex(Index index){
    return c_gridArray2d.at(index.r).at(index.c);
}

int GridController::calculateCellSize() const {
    int rows = read(qmlObject(), "rows").toInt();
    int columns = read(qmlObject(), "columns").toInt();
    int spacing = read(qmlObject(), "spacing").toInt();
    int width = read(qobject_cast<Item>(qmlObject()->parent()), "width").toInt() - (spacing * columns);
    int height = read(qobject_cast<Item>(qmlObject()->parent()), "height").toInt() - (spacing * rows);
    int size = qMin(width / columns, height / rows);
    return size - (size * .2);
}

Index GridController::cellIndex(Game::CellType type) const{
    for(int row = 0; row < c_gridArray2d.size(); row++){
        for(int col = 0; col < c_gridArray2d.at(row).size(); col++){
            if(c_gridArray2d.at(row).at(col)->type() == type){
                return Index(row, col);
            }
        }
    }
    return Index();
}

void GridController::swapCells(Index first, Index second){
    CellController *tmp = c_gridArray2d[first.r][first.c];
    c_gridArray2d[first.r][first.c] = c_gridArray2d[second.r][second.c];
    c_gridArray2d[second.r][second.c] = tmp;

    checkIfSolved();
}

/*public*/
void GridController::loadLevel(Level &level, bool shuffle){
    clear();

    c_hints = level.hints();
    write(c_qmlObject, "rows", level.rows());
    write(c_qmlObject, "columns", level.columns());

    if(shuffle) level.shuffle();

    int cellSize = calculateCellSize();

    for(int row = 0; row < level.rows(); row++){
        GridArray gridArray;
        for(int col = 0; col < level.columns(); col++){
            int type = level.hints().at(row * level.columns() + col).toInt();
            CellController *cellController = createCellController(cellSize);
            cellController->setType(static_cast<Game::CellType>(type));
            gridArray.append(cellController);
        }
        c_gridArray2d.append(gridArray);
    }
}

void GridController::moveCellsTo(Game::MoveDirection direction){
    Index transparentCell = cellIndex(Game::CellType::Transparent);
    Index indexes[] = {
        Index(transparentCell.r, transparentCell.c + 1), // Flip To Left
        Index(transparentCell.r, transparentCell.c - 1), // Flip To Right
        Index(transparentCell.r + 1, transparentCell.c), // Flip To Up
        Index(transparentCell.r - 1, transparentCell.c)  // Flip To Down
    };
    int rows = read(c_qmlObject, "rows").toInt();
    int columns = read(c_qmlObject, "columns").toInt();
    Index cell = indexes[direction];

    if(cell.isValid(rows, columns) && atIndex(cell)->canMove()){
        emit makeMoveSound();
        int spacing = read(c_qmlObject, "spacing").toInt();
        switch(direction){
        case Game::MoveDirection::Left:{
            atIndex(cell)->moveLeft(spacing);
            atIndex(transparentCell)->moveRight(spacing);
            break;
        }
        case Game::MoveDirection::Right:{
            atIndex(cell)->moveRight(spacing);
            atIndex(transparentCell)->moveLeft(spacing);
            break;
        }
        case Game::MoveDirection::Up:{
            atIndex(cell)->moveUp(spacing);
            atIndex(transparentCell)->moveDown(spacing);
            break;
        }
        case Game::MoveDirection::Down:{
            atIndex(cell)->moveDown(spacing);
            atIndex(transparentCell)->moveUp(spacing);
            break;
        }
        default: break;
        }
        swapCells(transparentCell, cell);
    }
}

/*public virtual*/
void GridController::info() const{
    dbg << "GRID INFO:";
    return IQmlComponentController::info();
}
