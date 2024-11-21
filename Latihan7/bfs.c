#include <stdio.h>
#include "queue.h"
#include "boolean.h"

#define MXN 100

int N;
char arr[MXN][MXN];
boolean visited[MXN][MXN];
int dist[MXN][MXN];

int main() {
    scanf("%d", &N);

    int startX, startY, endX, endY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (arr[i][j] == 'B') {
                endX = i;
                endY = j;
            }
            visited[i][j] = false;
            dist[i][j] = -1;
        }
    }

    Queue q;
    CreateQueue(&q);
    ElType start;
    start.row = startX;
    start.col = startY;
    enqueue(&q, start);
    visited[startX][startY] = true;
    dist[startX][startY] = 0;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    boolean found = false;

    while (!isEmpty(q)) {
        ElType pos;
        dequeue(&q, &pos);
        int x = pos.row;
        int y = pos.col;

        if (x == endX && y == endY) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!visited[nx][ny] && arr[nx][ny] != '#') {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    ElType nextPos;
                    nextPos.row = nx;
                    nextPos.col = ny;
                    enqueue(&q, nextPos);
                }
            }
        }
    }

    if (found) {
        printf("Ya\n");
        printf("%d\n", dist[endX][endY]);
    } else {
        printf("Tidak\n");
    }

    return 0;
}