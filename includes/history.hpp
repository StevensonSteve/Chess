#pragma once

struct Coordinate {
    int x;
    int y;
};

struct Move {
    Piece piece;
    Coordinate from;
    Coordinate to;
};

