//////////////TopSort.h////////////////
#ifndef TOPSORT_H
#define TOPSORT_H

void TopSort(AdjGraph * G) {
    int i, j;
    int St[MAXV], top = -1;
    ArcNode * p;
    for (i = 0; i < G->n; i ++) {
        G->adjlist[i].count = 0;
    }
    for (i = 0; i < G->n; i ++) {
        p = G->adjlist[i].firstarc;
        while (p != NULL) {
            G->adjlist[p->adjvex].count ++;
            p = p->nextarc;
        }
    }
    for (i = 0; i < G->n; i ++) {
        if (G->adjlist[i].count == 0) {
            top ++;
            St[top] = i;
        }
    }
    while (top > -1) {
        i = St[top];
        top --;
        printf("%d ", i);
        p = G->adjlist[i].firstarc;
        while (p != NULL) {
            j = p->adjvex;
            G->adjlist[j].count --;
            if (G->adjlist[j].count == 0) {
                top ++;
                St[top] = j;
            }
            p = p->nextarc;
        }
    }
}

#endif  //TOPSORT_H