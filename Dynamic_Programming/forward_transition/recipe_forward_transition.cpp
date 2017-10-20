//In most cases the states can be iterated through in lexicographical order.
//To do this you have to ensure that if I = (i1, i2, i3, ..., ik) directly depends on J = (j1, j2, j3, ..., jk) then I is lexicographically greater that J.
//This can be achieved by permuting parameters (like using (j,i) instead of (i,j)) 
//or reversing them. But it is usually easier to change the order and direction of nested loops. Here is general code of lexicographical traversion:
  for (int i1 = 0; i1<N1; i1++)
    for (int i2 = 0; i2<N1; i2++)
      ...
        for (int ik = 0; ik<Nk; ik++) {
          //get some states (j1, j2, j3, ..., jk) -> jres by performing transitions
          //and handle them
        }
