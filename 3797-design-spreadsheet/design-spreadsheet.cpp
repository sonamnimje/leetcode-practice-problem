class Spreadsheet {
    vector<vector<int>> grid;
    int rows;

    // Parse "A1" → (row, col)
    pair<int,int> parseCell(const string &cell) {
        char colChar = cell[0];
        int col = colChar - 'A';          // convert column letter
        int row = stoi(cell.substr(1)) - 1; // 1-indexed → 0-indexed
        return {row, col};
    }

    // Get value of operand (either number or cell reference)
    int getOperandValue(const string &op) {
        if (isdigit(op[0])) {
            return stoi(op); // numeric constant
        } else {
            auto [r, c] = parseCell(op);
            if (r >= 0 && r < rows && c >= 0 && c < 26)
                return grid[r][c];
            return 0;
        }
    }

public:
    Spreadsheet(int rows) : rows(rows) {
        grid.assign(rows, vector<int>(26, 0)); // initialize all to 0
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        // formula is always of form "=X+Y"
        formula = formula.substr(1); // remove '='
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        return getOperandValue(left) + getOperandValue(right);
    }
};
