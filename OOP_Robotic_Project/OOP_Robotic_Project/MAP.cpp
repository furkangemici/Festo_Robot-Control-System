#include "MAP.h"
#include "Point.h"
#include <stdexcept> 
#include <iomanip>

MAP::MAP() : numberX(0), numberY(0), gridSize(0) {}

MAP::MAP(int numberX, int numberY, double gridSize)
    : numberX(numberX), numberY(numberY), gridSize(gridSize) , 
    grid(numberX, std::vector<int>(numberY, 0)) {

}

void MAP::insertPoint(const Point& point) {
    int indexX = static_cast<int>(point.getX() / this->gridSize);
    int indexY = static_cast<int>(point.getY() / this->gridSize);

    // Harita sýnýrlarýný kontrol et
    if (indexX < 0 || indexY < 0 || indexX >= numberX || indexY >= numberY) {
        std::cout << "Expanding grid for point (" << indexX << ", " << indexY << ")" << std::endl;
        setGrid(indexX, indexY, 1);
    }
    else {
        grid[indexX][indexY] = 1;
        std::cout << "Point added at (" << indexX << ", " << indexY << ")" << std::endl;
    }
}

int MAP::getGrid(int indexX, int indexY) const {
    if (indexX >= 0 && indexX < numberX && indexY >= 0 && indexY < numberY) {
        return grid[indexX][indexY];
    }
    return -1;
}

void MAP::setGrid(int indexX, int indexY, int value) {
    const int expandBlockSize = 1; // Blok geniþletme boyutu

    // Negatif X koordinatlarý için geniþlet
    if (indexX < 0) {
        int expandAmount = (-indexX + expandBlockSize - 1) / expandBlockSize * expandBlockSize;
        std::cout << "Expanding grid in the negative X direction by " << expandAmount << " units." << std::endl;
        grid.insert(grid.begin(), expandAmount, std::vector<int>(numberY, 0));
        numberX += expandAmount;
        indexX += expandAmount;
    }

    // Negatif Y koordinatlarý için geniþlet
    if (indexY < 0) {
        int expandAmount = (-indexY + expandBlockSize - 1) / expandBlockSize * expandBlockSize;
        std::cout << "Expanding grid in the negative Y direction by " << expandAmount << " units." << std::endl;
        for (auto& row : grid) {
            row.insert(row.begin(), expandAmount, 0);
        }
        numberY += expandAmount;
        indexY += expandAmount;
    }

    // Pozitif X koordinatlarý için geniþlet
    if (indexX >= numberX) {
        int expandAmount = (indexX - numberX + expandBlockSize) / expandBlockSize * expandBlockSize;
        std::cout << "Expanding grid in the positive X direction by " << expandAmount << " units." << std::endl;
        grid.resize(numberX + expandAmount, std::vector<int>(numberY, 0));
        numberX += expandAmount;
    }

    // Pozitif Y koordinatlarý için geniþlet
    if (indexY >= numberY) {
        int expandAmount = (indexY - numberY + expandBlockSize) / expandBlockSize * expandBlockSize;
        std::cout << "Expanding grid in the positive Y direction by " << expandAmount << " units." << std::endl;
        for (auto& row : grid) {
            row.resize(numberY + expandAmount, 0);
        }
        numberY += expandAmount;
    }

    // Deðeri ata
    grid[indexX][indexY] = value;
    std::cout << "Grid updated at (" << indexX << ", " << indexY << ") with value: " << value << std::endl;

}

void MAP::clearMap() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0); // Satýrý sýfýrla
    }
}

void MAP::printInfo() {
    std::cout << "Map Information:" << std::endl;
    std::cout << "NumberX: " << numberX << std::endl;
    std::cout << "NumberY: " << numberY << std::endl;
    std::cout << "GridSize: " << gridSize << std::endl;
}


int MAP::getNumberX() const {
    return numberX;
}

int MAP::getNumberY() const {
    return numberY;
}

double MAP::getGridSize() const {
    return gridSize;
}

void MAP::setGridSize(double _gridsize) {
    if (_gridsize > 0) {
        gridSize = _gridsize;
    }
    else {
        throw std::invalid_argument("Grid size must be positive");
    }
}

std::ostream& operator<<(std::ostream& os, const MAP& map) {
    for (int x = 0; x < map.getNumberX(); ++x) { // Satýrlar (X ekseni)
        for (int y = 0; y < map.getNumberY(); ++y) { // Sütunlar (Y ekseni)
            os << (map.getGrid(x, y) ? 'x' : '.') << ' ';
        }
        os << '\n';
    }
    return os;
}

void MAP::showMap() const {
    /*for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell ? "x" : ".");
        }
        std::cout << "\n";
    }*/

    // write it with i and j
    for (int i = 0; i < numberX; i++) {
        for (int j = 0; j < numberY; j++) {
            std::cout << (grid[i][j] ? "x" : ".");
        }

    }

}
