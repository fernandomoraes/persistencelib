Persistence Lib

Acredito que trabalhar com dados em linguagem C/C++ em trabalhos acadêmicos ou pequenos projetos pode-se tornar custoso e um bucado chato.
A idéia é abstrair toda essa abertura de arquivos e toda dor de cabeça na hora de gravar e ler os dados. Isso não nenhum 
tipo de SGDB ou coisa do tipo, a propósito. Um emboço bem simples de seu uso seria:

<B>define CONTATOS "contatos"<BR />
define ENDERECOS "endereco"<BR /><BR />
createTable(CONTATOS, "nome endereco email telefone");<BR />
createTable(ENDERECOS, "id* rua bairro cidade estado"); //* indica que a coluna é auto-incremento<BR />
insertInto(CONTATOS, "Fernando", "1", "fernandosmoraes@msn.com", "00000000");<BR />
insertInto(ENDERECOS, "Av. Centenario", "Centro", "Criciuma", "Santa Catarina");

</B>
