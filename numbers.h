//
// Created by paxo on 06/05/2024.
//

#ifndef BUSCAMINAS_NUMBERS_H
#define BUSCAMINAS_NUMBERS_H

class Numbers {
public:
    void setNumbers(Box **&cell, int size) {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (cell[i][j].getMine()) {
                    // Arriba
                    if (i > 0)
                        cell[i - 1][j].close_mines++;

                    // Izquierda
                    if (j > 0)
                        cell[i][j - 1].close_mines++;

                    // Abajo
                    if (i < size - 1)
                        cell[i + 1][j].close_mines++;

                    // Derecha
                    if (j < size - 1)
                        cell[i][j + 1].close_mines++;

                    // Arriba izquierda
                    if (i > 0 && j > 0)
                        cell[i - 1][j - 1].close_mines++;

                    // Arriba derecha
                    if (i > 0 && j < size - 1)
                        cell[i - 1][j + 1].close_mines++;

                    // Abajo izquierda
                    if (i < size - 1 && j > 0)
                        cell[i + 1][j - 1].close_mines++;

                    // Abajo derecha
                    if (i < size - 1 && j < size - 1)
                        cell[i + 1][j + 1].close_mines++;
                }
            }
        }
    }

    void resetNumbers(Box **&cell, int &size) {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                cell[i][j].close_mines = 0;
            }
        }
    }
};

#endif //BUSCAMINAS_NUMBERS_H
