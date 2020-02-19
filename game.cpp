#include "game.h"

QQmlEngine * Game::c_engine = nullptr;

/*ctor*/
Game::Game(QObject *parent) : QObject(parent){

}

/*public*/
QQmlEngine * Game::engine(){
    return Game::c_engine;
}

void Game::setEngine(QQmlEngine *engine){
    if(Game::c_engine != engine){
        Game::c_engine = engine;
    }
}

QQuickItem * Game::createQmlObject(QString const name){
    QQmlComponent component(Game::engine(), QUrl("qrc:/qml/Cpp/" + name + ".qml"));
    QQuickItem * qmlComponent = qobject_cast<QQuickItem *>(component.create());
    return qmlComponent;
}

QString Game::cellTypeAsString(CellType type){
    return staticMetaObject.enumerator(staticMetaObject.indexOfEnumerator("CellType")).valueToKey(type);
}

QString Game::fullImagePath(CellType type){
    return QString("qrc:/assets/svg/icons/" + cellTypeAsString(type) + ".svg");
}
