/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function (rowsCount, colsCount) {
    const output = [];
    if (this.length !== (rowsCount * colsCount)) {
        return output
    }
    for (let rowIndex = 0; rowIndex < rowsCount; rowIndex++) {
        output[rowIndex] = [];
        for (let columnIndex = 0; columnIndex < colsCount; columnIndex++) {
            if (columnIndex % 2 === 0) {
                output[rowIndex][columnIndex] = this[rowsCount * columnIndex + rowIndex];
            } else {
                output[rowIndex][columnIndex] = this[rowsCount * columnIndex + (rowsCount - rowIndex - 1)];
            }
        }
    }
    return output;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */