/*  ggt.c   Groesster gemeinsamer Teiler ggt zweier Zahlen   */

int ggt(int x, int y) { /* gibt ggt(x,y) zurueck, falls x oder y nicht 0 */
  int c;                /* und gibt 0 zurueck fuer x=y=0.   */
  if ( x < 0 ) x = -x;  
  if ( y < 0 ) y = -y;
  while ( y != 0 ) {          /* solange y != 0 */
    c = x % y; x = y; y = c;  /* ersetze x durch y und
				 y durch den Rest von x modulo y */
  }
  return x;
}
