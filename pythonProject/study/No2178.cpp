
#include <iostream>
#include <queue>

using namespace std;
/*C++언어에서는 앞에 std::cout<<"asdfsa" 이렇게 써야하는데
* namespace std를 사용한다고 선언 해줌으로써 std를 모두 생략 가능
*/

int N, M;

int direction_x[] = {-1, 0, 1, 0}; //x축(행)으로 이동
int direction_y[] = {0, 1, 0, -1}; //y축(열)으로 이동

/*중간에 0을 넣은 이유?
*for문에서 i가 0일때를 예로 들으면
*direction_x[0] == -1 , direction_y[0] == 0 => 이말은 y의 이동을 배제하고 x좌표로만 이동한다는 뜻
*중간에 0을 안넣으면 direction_x,y 가 한번에 이동하여 로직이 꼬임
*/

int maze[101][101]; //전체 맵

queue<pair<int, int>> que;
/*pair란?
* 두 개의 개체를 하나의 단일 개체로 처리하는 기능
* C에선 구조체 역할과 비슷
* 
* ex)pair<int,float>hello
* 
* struct hello{
*  int num1;
*  float num2;
* }
* 
* 랑 동일한 기능을 가졌음
* 
* 사용법)
* 1.선언
* pair <int,float> hello(1,1.5);
* 또는
* hello=make_pair(1,1.5);
* 
*2.데이터 접근
* (객체 쓰듯이 사용)
* hello.first==1;
* hello.second==2;
* 
* first,second 를 통해 데이터 접근 가능
* 
* 3개도 되는지는...잘 모르겠어요 ㅎㅎ
*/

//bfs함수 선언
void bfs()
{

    que.push(make_pair(0, 0)); // int형 2개의 pair로 선언된 que에 0,0 삽입(시작점)
    pair<int, int> current;    //int형 2개의 pair로 current 선언
    int nx, ny;                //방향을 받을 변수 선언
    //int count = 0;
    while (!que.empty())
    {                          //큐에 뭐라도 있을 경우 while문 실행
        current = que.front(); //큐의 맨 앞 인자를 current에 넣음(첫번째 while루프면 0,0)
        que.pop();             //넣은걸 삭제(pop) 시킴(방문했으니 삭제)
        for (int i = 0; i < 4; i++)
        { //갈수 있는곳 탐색
            nx = current.second + direction_x[i];
            ny = current.first + direction_y[i]; //방향변수에 방향 넣어줌
            if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] == 1)
            //조건1 : nx,ny는 0보다 같거나 커야하고 미로의 최대치를 넘으면 안된다.
            //조건2 : maze[ny][nx]는 1이여야한다. (0은 못가니까 막힘)
            {
                que.push(make_pair(ny, nx));                            // 조건을 만족했을 경우 큐에 ny,nx 좌표를 넣어준다.
                maze[ny][nx] = maze[current.first][current.second] + 1; // 해당 좌표의 값을 이전 좌표의 값에 +1 시켜준다.
                                                                        //current는 현재 que.front()로 인해 큐의 맨 앞값이 들어가 있는 상태
                                                                        //만약 어떤 한 좌표의 값이 1이면 그 좌표에서 갈 수 있는 모든 점들의 값이 +1된다.
            }
        }
    }

    return;
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf_s("%1d", &maze[i][j]);
        }
    }

    bfs();
    cout << maze[N - 1][M - 1];
    return 0;
}