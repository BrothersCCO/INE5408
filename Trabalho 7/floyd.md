Complexidade do algoritmo de Floyd modificado
=============================================
```
FloydModificado()
início
	para i = 1 até n faça
		para j = 1 até n faça
			A[i,j] <- D[i,j];
			R[i,j] <- 0;
		fim para
	fim para
	para i = 1 até n faça
		A[i,i] <- 0;
	fim para
	para k = 1 até n faça
		para i = 1 até n faça
			para j = 1 até n faça
				se A[i,k] + A[k,j] < A[i,j] então
					A[i,j] <- A[i,k] + A[k,j];
					R[i,j] <- k;
			fim para
		fim para
	fim para
fim
```
O algoritmo de Floyd consiste de três loops:

Primeiro loop
-------------
```
para i = 1 até n faça
	para j = 1 até n faça
		A[i,j] <- D[i,j];
		R[i,j] <- 0;
	fim para
fim para
```
- O conteúdo do loop interno possui custo `2`, pois são feitas apenas duas atribuições.
- O loop interno possui um custo de `1` para atribuição na inicialização de *i*; `n+1` para os testes que serão feitos; e `n` para a quantidade de incrementos que serão feitos; além do custo `2` do seu conteúdo executado `n` vezes. Portanto, seu custo total é de `2n + n + n+1 + 1` ou `4n + 2`.
- O loop externo possui um custo de `1` para atribuição na inicialização de *i*; `n+1` para os testes que serão feitos; e `n` para a quantidade de incrementos que serão feitos; além do custo `4n + 2` do seu conteúdo executado `n` vezes. Portanto, seu custo total é de `n * (4n + 2) + n + n+1 + 1` ou `4n^2 + 4n + 2`.

O custo deste primeiro loop é de `4n^2 + 4n + 2`.

Segundo loop
------------
```
para i = 1 até n faça
	A[i,i] <- 0;
fim para
```
- O conteúdo do loop possui custo `1`, pois é feita apenas uma atribução.
- O loop interno possui um custo de `1` para atribuição na inicialização de *i*; `n+1` para os testes que serão feitos; e `n` para a quantidade de incrementos que serão feitos; além do custo `1` do seu conteúdo executado `n` vezes. Portanto, seu custo total é de `n + n + n+1 + 1` ou `3n + 2`.

Terceiro loop
-------------
```
para k = 1 até n faça
	para i = 1 até n faça
		para j = 1 até n faça
			se A[i,k] + A[k,j] < A[i,j] então
				A[i,j] <- A[i,k] + A[k,j];
				R[i,j] <- k;
		fim para
	fim para
fim para
```
Este loop tem dois loops internos. O mais interno possui uma condição:
```
se A[i,k] + A[k,j] < A[i,j] então
  A[i,j] <- A[i,k] + A[k,j];
  R[i,j] <- k;
```
- O bloco interno do teste possui custo `3`, pois são feitas uma soma e duas atribuições.
- O custo do teste é `2`, pois tem uma adição e uma comparação. A parte interna do teste possui um custo `3`, pois tem uma soma e duas atribuições. Portanto, seu custo total é `5`.

- O loop interno possui um custo de `1` para atribuição na inicialização de *i*; `n+1` para os testes que serão feitos; e `n` para a quantidade de incrementos que serão feitos; além do custo `5` do seu conteúdo executado `n` vezes. Portanto, seu custo total é de `5n + n + n+1 + 1` ou `7n + 2`.
- O loop intermediário possui um custo de `1` para atribuição na inicialização de *i*; `n+1` para os testes que serão feitos; e `n` para a quantidade de incrementos que serão feitos; além do custo `7n + 2` do seu conteúdo executado `n` vezes. Portanto, seu custo total é de `n * (7n + 2) + n + n+1 + 1` ou `7n^2 + 4n + 2`.
- O loop externo possui um custo de `1` para atribuição na inicialização de *i*; `n+1` para os testes que serão feitos; e `n` para a quantidade de incrementos que serão feitos; além do custo `7n^2 + 4n + 2` do seu conteúdo executado `n` vezes. Portanto, seu custo total é de `n * (7n^2 + 4n + 2) + n + n+1 + 1` ou `7n^3 + 4n^2 + 4n + 2`.

Conclusão
=========
Separando a função em três partes representadas pelos loops, temos que a soma dos custos é de `4n^2 + 4n + 2` + `3n + 2` + `7n^3 + 4n^2 + 4n + 2`, que pode ser reduzido para `7n^3 + 8n^2 + 11n + 6`. Desconsiderando os termos que não são predominantes e a constante que multiplica o custo, podemos concluir que o algoritmo apresentado tem complexidade `O(n^3)`.

Segue o código reescrito em C++:
Código em C++
-------------
```
void floyd_modificado(int** d, int n) {
  int a[n][n], r[n][n];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      a[i][j] = d[i][j], r[i][j] = 0;

  for (int i = 0; i < n; ++i)
    a[i][i] = 0;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        if (a[i][k] + a[k][j] < a[i][j])
          a[i][j] = a[i][k] + a[k][j], r[i][j] = k;
}
```
