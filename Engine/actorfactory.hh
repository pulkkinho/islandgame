#ifndef ACTORFACTORY_HH
#define ACTORFACTORY_HH

#include <QJsonObject>
#include <string>
#include <vector>

/**
 * @file
 * @brief Singleton class that creates actors. Common actors include the different
 * @brief sea animals and other actors defined in the actors.json file.
 * @brief Animals include: Dolphin, Kraken, Seamunster and Shark.
 * @brief Common actors include: Boat and Vortex.
 */

namespace Logic {

/**
 * @brief Singleton class for creating actors.
 *
 * The factory is requested to read a JSON file, after which it will requested
 * to return a data structure, which containts the read actors.
 */
class ActorFactory {

  public:

    /**
     * @return A reference to the factory.
     */
    static ActorFactory& getInstance();

    /**
     * @brief readJSON reads actors from a JSON file.
     * @exception IOException Could not open the file Assets/actors.json for reading.
     * @exception FormatException Format of the file Assets/actors.json is invalid.
     * @post Exception quarantee: basic
     */
    void readJSON();

    /**
     * @brief Gets the animal actors read into the game.
     * @return The actors read from the JSON file. If the file is not read yet, or the actors don't exist, returns an empty vector.
     * @post Exception quarantee: nothrow
     */
    std::vector<std::string> getAnimalActors() const;

    /**
     * @brief Gets the common actors read into the game.
     * @return The actors read from the JSON file. If the file is not read, or the actors did not exist, will return an empty vector.
     * @post Exception quarantee: nothrow
     */
    std::vector<std::string> getCommonActors() const;

  private:

    ActorFactory();

    QJsonObject _json;

};

}

#endif
