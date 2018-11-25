#ifndef FINDROOTS_H
#define FINDROOTS_H

void findDiscriminant(mpf_t a, mpf_t b, mpf_t c, mpf_t discriminant);
int findNumRoots(mpf_t discriminant);
void findRoots(mpf_t a, mpf_t b, mpf_t c, mpf_t discriminant, int numRoots);

#endif
