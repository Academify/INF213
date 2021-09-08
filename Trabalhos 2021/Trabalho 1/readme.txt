Eu li as regras

Nome: Thiago Ferreira Peixoto
Matrícula: ES98893

Fontes de consulta:
* https://www.journaldev.com/37330/compare-strings-in-c-plus-plus#:~:text=The%20compare()%20function%20in,the%20strings%20are%20the%20same.
* http://www.decom.ufop.br/reinaldo/site_media/uploads/2011/bcc702/aula06-sobrecarga.pdf
* https://www.interviewbit.com/tutorial/merge-sort-algorithm/
* Práticas/arquivos desenvolvidos nas mesmas e aulas da disciplina.

Explicação:

Antes dessa explicação, gostaria de durante a correção deste trabalho, considerasse que tive diversos problemas oriundos de peculiaridades do c++ que atrapalharam e atrasaram meu desenvolvimento,
contudo, fiz o máximo que pude para seguir as melhores práticas de programação em c++, usando a memória de maneira eficiente na declaração e uso das variáveis.
Sei o quanto isso é importante em sua avaliação e espero que leve tudo isso em conta, e não apenas a saída final no terminal. As saídas não estão como no terminal, mas mostram as movimentações na carteira de forma completa.
Peço também que entre em contato comigo para que eu possa esclarecer todas as dúvidas a respeito de minha implementação desse trabalho.

Parágrafo (máx. 100 palavras): ---------------------------------------------------------------------------------------------

Para que os dados pudessem ser trabalhados, usei a biblioteca fstream para ler os arquivos .csv e salvei os dados em vetores de tamanho máximo 500000.
Construí as classes necessárias para armazenamento dos dados. Além de extrair os dados, criei vetor de eventos (como sugerido em aula), usei mergesort para a ordenação 
pelo fato de o merge sort ser um método eficiente mesmo no pior caso (n log n) e por ser estável, preservando assim a ordem correta dos diferentes tipos de eventos em uma mesma data.
O vetor de Cotações também foi ordenado usando o mergesort. A ideia era o uso conjugado com uma busca binária que pudesse achar com maior eficiência os registros consultados.

Toda memória alocada foi devidamente desalocada ao final do programa.

----------------------------------------------------------------------------------------------------------------------------

Feedback construtivo sobre a proposta do trabalho:

Nesse trabalho aprendi bastante sobre métodos de busca e ordenação, seus casos de uso, eficiência e implementações. Como possíveis ajustes, os meus próximos passos seriam fazer com que as buscas nos vetores
fossem ainda mais eficientes, usando busca binária para resgatar os registros desejados. Também, finalizaria a implementação das saídas especificadas para a correção automática.

Como feedback, gostaria de sugerir que para os próximos trabalhos sejam ponderadas algumas questões. Neste trabalho, o menor esforço foi para aprender a matéria ensinada, 
e o maior foi em construir uma estrutura básica que não diz respeito ao conteúdo chave do trabalho, o que faz com que a atividade se perca em propósito.
Uma sugestão para resolver esse problema seria a disponibilização de um material base para a realização dos trabalhos, que permitisse que o aluno fique focado em aprender o conteúdo ministrado,
semelhantemente ao que ocorre nas atividades páticas.
