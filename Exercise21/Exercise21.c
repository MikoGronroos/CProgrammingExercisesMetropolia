#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
   char buffer[256];
   char line[1024];
   FILE *fptr;

   printf("Enter file name: ");
   if (scanf("%255s", buffer) != 1) {
      fprintf(stderr, "No file name given.\n");
      return 1;
   }

   fptr = fopen(buffer, "r"); 
   if (fptr == NULL) {
      fprintf(stderr, "Cannot open file\n");
      return 1;
   }

   while (fgets(line, sizeof(line), fptr) != NULL) {
      line[strcspn(line, "\n")] = '\0';

      char *star = strchr(line, '*');
      if (line[0] == '$' && star != NULL) {
         unsigned char calc = 0;
         for (char *p = line + 1; p < star; p++) {
            calc ^= (unsigned char)*p;
         }

         unsigned int given;
         int ok = 0;
         if (sscanf(star + 1, "%2x", &given) == 1) {
            ok = (given == calc);
         }

      printf("%s %s\n", ok ? "[ OK ]" : "[FAIL]", line);

      }
   }

   fclose(fptr);
   return 0;
}
