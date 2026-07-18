# Pokemon Emerald Littleroot Clone

A 2D tile-based game clone of the starting town (Littleroot) from Pokemon Emerald, built with C++ and raylib.

## Prerequisites

- C++ compiler (g++)
- raylib 5.0.0 installed

## Building

```bash
make
```

## Running

```bash
./game
```

## Project Structure

- `src/` - Source code
- `src/assets/` - Game assets
- `lib/` - Required DLLs (Windows)

## How It Works

The game renders a 2D tile map with three layers:
- **Ground Layer** - Background textures (grass, paths)
- **Object Layer** - Buildings, trees, signs
- **Entity Layer** - Players, NPCs, items

Use arrow keys to move the player around the map.

## Development

See [PLAN.md](PLAN.md) for development notes and future plans.
