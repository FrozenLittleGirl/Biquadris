




bool Board::isShiftValid(size_t angle, size_t x, size_t y) {
    bool is_valid = true;
    int rotateAngle = currentBlock->getAngle() + angle;
        rotateAngle = rotateAngle % 360;
    if (rotateAngle < 0) {
        rotateAngle += 360; 
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char currentChar = ' ';
            if (rotateAngle == 0) {
                currentChar = currentBlock->getRotateDefault()[i][j];
            } else if (rotateAngle == 90) {
                currentChar = currentBlock->getRotate90()[i][j];
            } else if (rotateAngle == 180) {
                currentChar = currentBlock->getRotate180()[i][j];
            } else if (rotateAngle == 270) {
                currentChar = currentBlock->getRotate270()[i][j];
            }
            
            if (currentChar != ' ') {
                size_t currentAngle = currentBlock->getAngle();
                size_t blockX = currentBlock->getXcoord();
                size_t blockY = currentBlock->getYcoord();
                size_t currentX = currentBlock->getXcoord() + x;
                size_t currentY = currentBlock->getYcoord() + y;
                if (currentX + j < 0 || currentY + i < 0 || currentX + j > 19 || currentY + i > 19) {
                    is_valid = false;
                }
                if (theBoard[currentY + i][currentX + j].isOccupied() == true) {
                    if (currentX + j < blockX || currentY + i < blockY || 
                    currentX + j > blockX + 3 || currentY + i > blockY + 3) {
                        is_valid = false;
                    }
                    if (currentAngle == 0) {
                        if (currentBlock->getRotateDefault()[y + i][x + j] == ' ') {
                            is_valid = false;
                        }
                    } else if (currentAngle == 90) {
                        if (currentBlock->getRotate90()[y + i][x + j] == ' ') {
                            is_valid = false;
                        }
                    } else if (currentAngle == 180) {
                        if (currentBlock->getRotate180()[y + i][x + j] == ' ') {
                            is_valid = false;
                        }
                    } else if (currentAngle == 270) {
                        if (currentBlock->getRotate270()[y + i][x + j] == ' ') {
                            is_valid = false;
                        }
                    }
                }
                
                
            }
            
        }
    }
    return is_valid;
}


void Board::move(size_t angle, size_t x, size_t y) {
    char currentChar = ' ';
    size_t currentAngle = currentBlock->getAngle();
    vector<string> currentRotation;
    if (currentAngle == 0) {
        currentRotation = currentBlock->getRotateDefault();
    } else if (currentAngle == 90) {
        currentChar = currentBlock->getRotate90();
    } else if (currentAngle == 180) {
        currentChar = currentBlock->getRotate180();
    } else if (currentAngle == 270) {
        currentChar = currentBlock->getRotate270();
    }
    size_t currentX = currentBlock->getXcoord();
    size_t currentY = currentBlock->getYcoord();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (currentRotation[i][j] != ' ') {
                theBoard[currentY + i][currentX + j].clearCell();
            }
            
        }
    }
    size_t rotateAngle = currentAngle + angle;
    rotateAngle = rotateAngle % 360;
    if (rotateAngle < 0) {
        rotateAngle += 360; 
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
        }
    }
    
}
