#include "Map.h"  
 // ��u�T�� 10227150 �յq��  ��u�T�� 10227135 ���@��  
plink Map::push(int x, int y) {  
    if(curPos==NULL){  
        curPos = new pnode;  
        curPos->x = x;  
        curPos->y = y;  
        curPos->next = NULL;  
        return curPos;  
    } else {  
        plink newnode = new pnode;  
        newnode->x = x;  
        newnode->y = y;  
        newnode->next = curPos;  
        curPos = newnode;  
        return curPos;  
    }  
}  

void Map::reset() {
	curPos = NULL ;
}
  
plink Map::pop(int* x, int* y){  
    if(curPos == NULL){  
        *x = -1;  
        return NULL;  
    } else {  
        plink top = curPos;  
        *x = curPos->x;  
        *y = curPos->y;  
        curPos = curPos->next;  
        delete top;  
        return curPos;  
    }  
}   
  
int Map::chkExit(int x, int y, int ex, int ey){  
    if(x==ex && y==ey){  
        return 1;  
    } else {  
        return 0;  
    }  
} 

