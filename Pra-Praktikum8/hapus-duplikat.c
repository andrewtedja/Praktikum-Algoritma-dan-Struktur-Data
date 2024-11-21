#include "listlinier.h"
#include <stdio.h>

List hapusDuplikat(List l){
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
*/
    List hasil;
    CreateList(&hasil);  

    if (isEmpty(l)) {
        return hasil;  
    }

    Address p = FIRST(l); 
    while (p != NULL) {
        ElType current = INFO(p);
        boolean isDuplicate = false;

        Address q = NEXT(p);
        while (q != NULL && INFO(q) == current) {
            isDuplicate = true;
            q = NEXT(q);
        }


        if (!isDuplicate) {
            insertFirst(&hasil, current);  
        }

        p = q;
    }

    return hasil;  
}
