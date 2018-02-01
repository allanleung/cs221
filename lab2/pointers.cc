int main () {
  int x = 5, y = 15;
  int * p1, *p2;
		  // value of	x	   y	p1	    p2
		  //		    5	   15	uninit	uninit
  p1 = &x;       //   p1 is poiting to x
                 //     5      15   &x     uninit
  p2 = &y;       //   p2 is pointing to y
                 //     5      15   &x      &y
  *p1 = 6;       //   value of p1 is now 6
                 //     6      15   &x      &y
  *p1 = *p2;     //   value of p1 is now value of p2
                 //     15     15   &x      &y
  p2 = p1;       //   this is where pointer move, p2 is now pointing at where p1 is at.
                 //     15     15   &x      &x
  *p1 = *p2+10;  //   this reads, the value of p1 is now p2 + 10, so p1 is x, x is 10, therefore its 25
                 //     25     15   &x      &x
  return 0;
}
