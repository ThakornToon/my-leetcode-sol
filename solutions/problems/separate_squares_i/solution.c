double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double maxY = INT_MIN;
    double minY = INT_MAX;

    for (int i = 0; i < squaresSize; i++) {
        int y = squares[i][1];
        if (maxY < y + squares[i][2]) {
            maxY = y + squares[i][2];
        }
        if (minY > y) {
            minY = y;
        }
    }

    while (maxY - minY > 1e-5) {
        double midY = minY + (maxY - minY) / 2.0;
        double upArea = 0.0;
        double downArea = 0.0;
        for (int i = 0; i < squaresSize; i++) {
            double side = squares[i][2];
            if (midY >= squares[i][1] + side) {
                downArea += (side * side);
            } else if (midY <= squares[i][1]) {
                upArea += (side * side);
            } else {
                downArea += (midY - squares[i][1]) * side;
                upArea += (squares[i][1] + side - midY) * side;
            }
        }
        if (fabs(upArea - downArea) < 1e-5) {
            maxY = midY; // พยายามหา y ที่น้อยที่สุด
        } else if (upArea > downArea) {
            minY = midY;
        } else {
            maxY = midY;
        }
    }

    return minY;
}