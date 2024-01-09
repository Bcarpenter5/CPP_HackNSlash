#include "Map.h"
#include "Game.hpp"
#include <fstream>
#include "nlohmann/json.hpp"
#include <vector>

using json = nlohmann::json;

// int lvl1[20][25] = {
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,0,0,0,0,0,1,1,1},
//     {1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1},
//     {1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0,0,0,0,0,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//     {2,1,2,1,0,0,0,0,0,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,0},
//     {1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//     {1,1,1,1,0,0,0,0,0,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,0},
//     {1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//     {1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//     {2,1,2,1,2,1,2,1,1,2,1,2,1,2,1,1,1,1,1,1,1,1,1,1,0},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//     {2,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
//     };



Map::Map() {
}

Map::~Map() {
}

void Map::LoadMap(std::string path, int sizeX, int sizeY){
    char tile;
    std::fstream mapFile;
    mapFile.open(path);// loads to this point
    std::cout << "path: " << path << std::endl;
    std::cout << "sizeX: " << sizeX << std::endl;
    std::cout << "sizeY: " << sizeY << std::endl;

    for(int y = 0; y < sizeY; y++){
        for(int x = 0; x < sizeX; x++){
            mapFile.get(tile);// get char from file 
            Game::AddTile(atoi(&tile)-1, x * 32, y * 32);
            mapFile.ignore();
        }
    }

    mapFile.close();
}

void Map::LoadMap(std::string path){
    char tile;
    std::fstream mapFile;
    mapFile.open(path);// loads to this pointgg
    json j;
    mapFile >> j;
    // set the values for tilesWide and  tilesHigh
    if(j.is_object()){
        int tilesWide = j["project"]["tilesWide"];
        int tilesHigh = j["project"]["tilesHigh"];
        std::cout << "tilesWide: " << tilesWide << std::endl;
        std::cout << "tilesHigh: " << tilesHigh << std::endl;

        std::vector<int> tiles;
        // get the array of tiles
         const json& tilesArray = j["project"]["tiles"];
         if(tilesArray.is_array()){
             for (const auto& tile : tilesArray){
                 tiles.push_back(tile);
             }
         }

         for (int y = 0; y < tilesHigh; y++){
             std::cout << "y: " << y << ":: ";
             for (int x =0; x < tilesWide; x++){
                 int tile = tiles[x + y*tilesWide];
                std::cout << tile << " ";
                Game::AddTile(tiles[x + y*tilesWide]-1, x * 32, y * 32);
            }
            std::cout << std::endl;
        }
    }
}

