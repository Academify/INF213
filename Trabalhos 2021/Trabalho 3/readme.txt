Eu li as regras

Nome: Thiago Ferreira Peixoto
Matrícula: ES98893

Descrição do trabalho:
Nesse trabalho construi um compressor de arquivos utilizando o código da árvore de Huffman.
Para montar a estrutura da árvore, utilizei do MySet que criamos em aulas passadas, bem como a priority queue.
Basicamente, o conversor funciona da seguinte forma: Primeiro lê todo o conteúdo do arquivo e o concatena em uma string.
Após isso, percorre essa string fazendo incrementos no vetor de frequência de acordo com o a posição sendo referenciada pelo char correspondente.
Depois o conversor cria a árvore de Huffman utilizando a frequência como base de compraração. Depois disso, o conversor percorre a árvore
de maneira a achar todos os códigos referentes aos caracteres dispostos na árvore e salva em um vetor de códigos.
Feito isso, transormamos os códigos em binário e depois para char. Esse char é o que será salvo no arquivo comprimido.
No arquivo comprimido, na primeira linha temos a quantidade de bits e o vetor de frequências. Nas linhas abaixo, está todo o conteúdo do arquivo.
Para descompressão, fazemos o caminho inverso. Lê-se a quantidade de bits e o vetor de frequências e aplicamos a engenharia reversa até obtermos
novamente a árvore de Huffman e através dos caracteres codificados, conseguirmos retornar aos caracteres originais. Tive dificuldade com os testes
no subimitty, mas a principal tarefa (compressão e descompressão) estão sendo realizadas correspondente.

Referências:
[fstream reference]: https://www.cplusplus.com/reference/fstream/fstream/
[fstream reference]: https://www.cplusplus.com/reference/fstream/ofstream/
[Bitset reference]: https://www.cplusplus.com/reference/bitset/bitset/
[StackOverflow](read-whole-ascii-file-into-c-stdstring): https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
[Huffman Code Visualization]: https://cmps-people.ok.ubc.ca/ylucet/DS/Huffman.html
Materiais do moodle da disciplina
Perguntas e respostas no fórum do moodle da disciplina

