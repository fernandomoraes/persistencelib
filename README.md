Persistence Lib

Acredito que trabalhar com dados em linguagem C/C++ em trabalhos acadêmicos ou pequenos projetos pode-se tornar custoso e um bucado chato.
A idéia é abstrair toda essa abertura de arquivos e toda dor de cabeça na hora de gravar e ler os dados. Isso não é nenhum 
tipo de SGDB ou coisa do tipo, a propósito. Um emboço bem simples de seu uso seria:

<pre><code>
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
</code></pre>


Por falta de tempo e tudo mais, as principais funções como <i>DELETE, SELECT</i> e <i>UPDATE</i> ainda não foram implementadas, mas espero que isso inspire e que seja escrito o resto até o fim.
