#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[]){
  if(argc != 3){
    printf("Usage: cp src dst");
    return 1;
  }

  FILE* src = fopen(argv[1], "rb");
  if(src == NULL){
    printf("%s not found", argv[1]);
    return 1;
  }

  FILE* dst = fopen(argv[2], "wb");
  if(dst == NULL){
    printf("%s not found", argv[2]);
    return 1;
  }

  BYTE buffer;

  while(fread(&buffer, sizeof(buffer), 1, src) != 0){ // While the number of bytes we read from the src file, per byte, to the buffer variable is not equal to 0
    fwrite(&buffer, sizeof(buffer), 1, dst);        // Write the byte in the buffer to the dst file
  }

  fclose(dst);
  fclose(src);
}
