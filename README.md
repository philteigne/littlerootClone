# Pokemon Emerald Littleroot Clone

This is a project for practicing game development in raylib and C++. The goal is to make an identical clone of the starting town name Littleroot in Pokemon emerald.

The game will have a defined 2D array serving as a map of tiles. The tiles each have attributes that determine what they look like, whether they can be accessed with and any interactions it would have with the player. The game will determine which tiles to draw and iterate over by calculating the visible tiles on the Users screen.  

The game will have a player that can be moved around the map as well as listen for events the player triggers. we will track the players position matches the position of a relevant tile.  

## Game Drawing

The game will consiste a grid of tiles with 3 draw layers to make up the map.

- **Ground Layer:** This consists of the background textures. All textures in this layer must fully fill their tile and have no transparency. Ground Layers have no boundaries.
- **Object Layer:** This consists of structures sitting on top of the ground, including buildings, signs, trees, bushes etc. These textures can have some transparency on them showing the Ground Layer texture behind it sometimes. Object layers would sometimes have boundaries. Tiles do not need to have an Object layer value.
- **Entity Layer:** This consists of characters, items etc. that could change positions. Entities should always have boundaries. Tiles do not need to have an Entity layer value.

Each Layer will be mapped to an individual array so that they can be moved independently of each other.

When the viewable map is being drawn each layer is passed a contained array of identifiers that represent the type of tile that should be rendered. The relevant layer then references that identifier against a vector of keys containing all details associated with that tile.

The objects can ovelay eachother in the object layer?

// TODO

I don't think we need ViewPort at all we should be able to give MapTiles a draw method, and have it draw the relevant tiles directly

Game should keep track of the player's location, it should pass the current location to the MapTiles draw method. The MapTiles draw method should load the relevant maptiles from the consts file then return the relevant tiles to game

I think MapTiles should just return a map object that Game draws. The MapTiles will be used to check for events, interactions and collision and that should probably be handled at the game level.

Textures should be loaded outside of the game loop but for now it's fine

It likely isn't worth it in the future to have tiles with texture layers and interaction. Textures and interactions can be managed in separate maps. Since they only need to be made properly once it is fine to hardcode map tiles to where they are supposed to be rather than to try and dynamically render each tile type. This also allows more freedom for different tile interactions and odd textures.

Look into raylib Camera2D

Convert texture structure to 3 layers.
Background Layer - Things like grass, paths, and flowers that render behind the player if they were to enter that tile.
Entity Layer - Include players, objects that change from visible to not visible or move locations. These would be overlaying on top of the normal background tiles
Foreground Layer - Items on this layer would be static but could hide portions of the tile beneath them, so either the top of tress/houses or the texture of a bush when a player enters.

Should separate display out of Game
https://www.mapeditor.org/ managing maps this way won't be practical for larger projects