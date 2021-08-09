# Simulador de um Atômato Finito Determinístico
Lucas Martins Soares

---

## Sobre

Esse simulador foi desenvolvido na disciplina de Linguagens Formais e Autômatos, para simular qualquer atômato finíto determinístico (AFD).

## Download, Compilação

Para obter o simulador é preciso baixar, compilar e executar. Para isso basta inserir os comandos abaixo no terminal:

```
git clone https://github.com/lucasmsoares96/AFD.git
cd afd
make 
```

## Funcionamento

Para que o simulador funcione, é preciso adicionar os conjuntos que compõem o autômato no arquivo afd.txt. Um modelo para este arquivo é fornecido junto com o código fonte. Em seguida execute o comando seguido pela palavra que deseja inserir no AFD.

```Bash
./afd abbab
```
O simulador irá retornar se o AFD aceita ou refeita a palavra informada.

```
Palavra: abbab

q0 + a -> q1 
q1 + b -> q2 
q2 + b -> qf 
qf + a -> qf 
qf + b -> qf 

Aceita
```
