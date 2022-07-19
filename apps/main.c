#include "playlist.h"
#include <stdio.h>

int main(){

    PlayList *circularList = PlayListCreate();

    PlayListAdd(circularList, "Rossi", "Lalala", 240);
    PlayListAdd(circularList, "Ramos", "Tururummm", 300);
    PlayListAdd(circularList, "Anitta", "Tututammm", 310);
    PlayListAdd(circularList, "Eminem", "Pararammm", 290);
    PlayListplay(circularList, 1);
    PlayListRemove(circularList, "Tururummm");
    printf("Apos a remocao:\n");
    PlayListplay(circularList, 1);
    
    return 0;
}