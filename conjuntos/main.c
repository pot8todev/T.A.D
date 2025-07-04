
typedef struct Vetor {
  int size;
  int maxSize;
  float dados;

} Vetor;
// podemos ter duas structs com mesma caracteristica
// mas com funços assosiadas diferentes
typedef struct conjunto {
  Vetor *Dados;

} Conjunto;
