#include <bits/stdc++.h>
using namespace std;

int board[9][9], ct;
bool cl[9][10], rw[9][10], ar[9][10];

void print_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j) cout << ' ';
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void fill(int n) {
    if (n == 81) {
        print_board();
        ct++;
        return;
    }
    int x = n / 9, y = n % 9;
    if (board[x][y] != 0) {
        fill(n + 1);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (!rw[x][i] && !cl[y][i] && !ar[x / 3 * 3 + y / 3][i]) {
                rw[x][i] = cl[y][i] = ar[x / 3 * 3 + y / 3][i] = true;
                board[x][y] = i;
                fill(n + 1);
                board[x][y] = 0;
                rw[x][i] = cl[y][i] = ar[x / 3 * 3 + y / 3][i] = false;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                rw[i][board[i][j]] = true;
                cl[j][board[i][j]] = true;
                ar[i / 3 * 3 + j / 3][board[i][j]] = true;
            }
        }
    }
    fill(0);
    cout << "there are a total of " << ct << " solution(s)." << endl;
}
