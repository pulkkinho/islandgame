#include "actorfactory.hh"
#include "formatexception.hh"
#include "ioexception.hh"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>

namespace Logic {

QString const ACTORDATA = ("Assets/actors.json");

ActorFactory::ActorFactory() {}

ActorFactory& ActorFactory::getInstance()
{

    static ActorFactory instance;
    return instance;

}

void ActorFactory::readJSON()
{

    QFile file (ACTORDATA);

    if (!file.open(QFile::ReadOnly))
    {
        throw Common::IoException("Could not read file");
    }

    QJsonDocument json = QJsonDocument::fromJson(file.readAll());
    if (json.isNull()) {
        throw Common::FormatException("JSON parsing failed for input file");
    }

    json_ = json.object();

}

std::vector<std::string> ActorFactory::getAnimalActors() const {

    std::vector<std::string> animalActors;
    QJsonArray animal = json_["Animal"].toArray();
    for (int i = 0; i < animal.size(); ++i) {
        animalActors.push_back(animal[i].toObject().value("name").toString().toStdString());
    }
    return animalActors;

}

std::vector<std::string> ActorFactory::getCommonActors() const {

    std::vector<std::string> commonActors;
    QJsonArray common = json_["Common"].toArray();
    for (int i = 0; i < common.size(); ++i) {
        commonActors.push_back(common[i].toObject().value("name").toString().toStdString());
    }
    return commonActors;

}

}
