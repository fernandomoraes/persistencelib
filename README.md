PERSISTENCE LIB C/C++

- Arquivo:
Inclua o arquivo PERSISTENCE.H  na pasta do seu projeto, depois utilize as diretivas no topo da página #include "persistence.h". Caso queira utilizar #include<persitence.h>, mova o arquivo para a pasta


- Como utilizar no seu prejeto:

#include "persistence.h"

// nome das tabelas
#define CONTATOS "contatos
#define ENDERECOS "enderecos"


int main(){
    createTable(CONTATOS, "nome endereco email telefone"); //nome da tabela e as colunas
    createTable(ENDERECOS, "id* rua bairro cidade estado"); //* indica que a coluna é auto-incremento

     insertInto(CONTATOS, "Fernando", "1", "fernandosmoraes@msn.com", "00000000");
     insertInto(ENDERECOS, "Av. Centenario", "Centro", "Criciuma", "Santa Catarina");

}




