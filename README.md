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