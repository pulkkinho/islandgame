#include "wheellayoutparser.hh"

#include "ioexception.hh"
#include "formatexception.hh"

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
namespace Logic {

WheelLayoutParser::WheelLayoutParser(std::string filePath)
{
    readJSON(filePath);
}

void WheelLayoutParser::readJSON(std::string filePath)
{
    QFile file(QString::fromStdString(filePath));

    if (!file.open(QFile::ReadOnly))
    {
        throw Common::IoException("Could not read file");
    }

    QJsonDocument json = QJsonDocument::fromJson(file.readAll());
    if (json.isNull()) {
        throw Common::FormatException("JSON parsing failed for input file");
    }

    lastRead_ = json.array();

}

std::vector<std::string> WheelLayoutParser::getSections()
{
    std::vector<std::string> sections;

    for (auto i = 0; i < lastRead_.size(); ++i){
        sections.push_back(lastRead_[i].toObject().value("name").toString().toStdString());
    }
    return sections;
}

std::vector<std::pair<std::string, int> > WheelLayoutParser::getChangesForSection(std::string section)
{
    std::vector<std::pair<std::string, int>> chances;

    for (auto i = 0; i < lastRead_.size(); ++i) {
        auto currentSection = lastRead_[i].toObject().value("name").toString().toStdString();
        if ( currentSection == section ) {
            auto chancesObject = lastRead_[i].toObject().value("chances").toObject();
            for(auto key: chancesObject.keys()){
                auto value = chancesObject.value(key);
                chances.push_back(std::make_pair<std::string, int>(key.toStdString(),
                                                                   value.toInt()));
            }
        }
    }
    return chances;
}

bool WheelLayoutParser::isFileRead()
{
    return !lastRead_.empty();
}
}
