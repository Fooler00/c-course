#include<windows.h>
#include <easyx.h>
#include <cstring>
#include <cstdlib> // 包含rand、srand函数
#include <ctime>   // 包含time函数
#include <graphics.h>
#include <vector>
#include <array>
#include <iostream>
#include <random>
class Board { // 类名首字母大写，符合命名规范
public:
    static int** init(int n) {
        // 创建一个n x n的二维数组
        int** array = new int *[n]; // 分配n行
        for (int i = 0; i < n; i++) {
            array[i] = new int [n]; // 分配n列
        }
        // 初始化数组的每个元素为0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                array[i][j] = 0; // 直接使用数组索引
            }
        }
        return array;
    };

    static int set_bombs(int n, int bombs, int **array) {
        srand(time(nullptr)); // 设置随机数种子
        for (int i = 0; i < bombs; i++) {
            int x = rand() % n; // 随机生成x坐标
            int y = rand() % n; // 随机生成y坐标
            array[x][y] = 1; // 将数组中对应位置设置为1，表示有炸弹
        }
        return 0; // 返回0表示成功
    };
};


//class widget{
//
//
//
//};

int main() {
    char *input;
    char *bombs;
//    initgraph(800,400,0);
//    InputBox(input,7,"输入雷阵大小与雷数","扫雷","示例：10 50",0,0,false);
    int n = 10 /*strtol(input, &bombs, 10)*/;
    int bombs_num = 50 //strtol(bombs,&bombs,10);
    int**array=Board::init(n);
    Board::set_bombs(n,bombs_num,array);
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            std::cout << array[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl;

    delete array;
    closegraph();
    return 0;
}

//int main(){
//    using namespace std;
//    int n=10;
//    vector<vector<int>> map;
//    for(int i=0;i<10;i++){
//        vector<int> line;
//        for(int j=0;j<10;j++){
//            line.push_back(0);
//        }
//        map.push_back(line);
//    }
//    for(int i=0;i<10;i++){
//        map[rand()%n][rand()%n]=1;
//    }
//
//    for(auto row:map){
//        for(auto it:row){
//            cout<<it<<" ";
//        }
//        cout<<endl;
//    }
//
//
//}
