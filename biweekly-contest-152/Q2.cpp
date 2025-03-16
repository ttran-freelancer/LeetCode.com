// https://leetcode.com/problems/design-spreadsheet/description

class Spreadsheet {
public:
    Spreadsheet(int rows) {
        m_data = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto c = parseCell(cell);
        m_data[c.first][c.second] = value;
    }
    
    void resetCell(string cell) {
        auto c = parseCell(cell);
        m_data[c.first][c.second] = 0;
    }
    
    int getValue(string formula) {
        auto pos = formula.find('+');
        string l = formula.substr(1, pos - 1);
        string r = formula.substr(pos + 1);
        int lvalue, rvalue;
        if (isCell(l)) {
            auto c = parseCell(l);
            lvalue = m_data[c.first][c.second];
        } else {
            lvalue = stoi(l);
        }
        if (isCell(r)) {
            auto c = parseCell(r);
            rvalue = m_data[c.first][c.second];
        } else {
            rvalue = stoi(r);
        }
        return lvalue + rvalue;
    }
private:
    pair<int, int> parseCell(string cell) {
        int row = stoi(cell.substr(1)) - 1;
        int col = cell[0] - 'A';
        return {row, col};
    }

    bool isCell(string s) {
        return s[0] >= 'A' && s[0] <= 'Z';
    }

    vector<vector<int>> m_data;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */