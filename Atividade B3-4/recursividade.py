class Produto:
    # Autores:
    #Bruno Tonaki
    #Eric Chagas
    
    # Equipe:
    # Bruno Tonaki
    # Eric Chagas
    # Felipe Torquato
    # Henrique Canosa

    # Data:
    # 24/09/2024
    # Prof Verissímo
    # Paradigma: Recursividade
    def __init__(self, nome, preco, validade, quantidade):
        self.nome = nome
        self.preco = preco
        self.validade = validade
        self.quantidade = quantidade

    def __repr__(self):
        return f"{self.nome} - R${self.preco:.2f} - Válido até: {self.validade} - Quantidade: {self.quantidade}"

def ordena_por_nome(produtos):
    if len(produtos) <= 1:
        return produtos
    else:
        meio = len(produtos) // 2
        esquerda = ordena_por_nome(produtos[:meio])
        direita = ordena_por_nome(produtos[meio:])

        return mescla_por_nome(esquerda, direita)

def mescla_por_nome(esquerda, direita):
    resultado = []
    while esquerda and direita:
        if esquerda[0].nome < direita[0].nome:
            resultado.append(esquerda.pop(0))
        else:
            resultado.append(direita.pop(0))
    resultado.extend(esquerda or direita)
    return resultado

def ordena_por_preco(produtos):
    if len(produtos) <= 1:
        return produtos
    else:
        meio = len(produtos) // 2
        esquerda = ordena_por_preco(produtos[:meio])
        direita = ordena_por_preco(produtos[meio:])

        return mescla_por_preco(esquerda, direita)

def mescla_por_preco(esquerda, direita):
    resultado = []
    while esquerda and direita:
        if esquerda[0].preco < direita[0].preco:
            resultado.append(esquerda.pop(0))
        else:
            resultado.append(direita.pop(0))
    resultado.extend(esquerda or direita)
    return resultado

def ordena_por_validade(produtos):
    if len(produtos) <= 1:
        return produtos
    else:
        meio = len(produtos) // 2
        esquerda = ordena_por_validade(produtos[:meio])
        direita = ordena_por_validade(produtos[meio:])

        return mescla_por_validade(esquerda, direita)

def mescla_por_validade(esquerda, direita):
    resultado = []
    while esquerda and direita:
        if esquerda[0].validade < direita[0].validade:
            resultado.append(esquerda.pop(0))
        else:
            resultado.append(direita.pop(0))
    resultado.extend(esquerda or direita)
    return resultado

def ordena_por_quantidade(produtos):
    if len(produtos) <= 1:
        return produtos
    else:
        meio = len(produtos) // 2
        esquerda = ordena_por_quantidade(produtos[:meio])
        direita = ordena_por_quantidade(produtos[meio:])

        return mescla_por_quantidade(esquerda, direita)

def mescla_por_quantidade(esquerda, direita):
    resultado = []
    while esquerda and direita:
        if esquerda[0].validade < direita[0].validade:
            resultado.append(esquerda.pop(0))
        else:
            resultado.append(direita.pop(0))
    resultado.extend(esquerda or direita)
    return resultado

def inserir_produtos():
    produtos = []
    num_produtos = int(input("Quantos produtos deseja inserir? "))

    for _ in range(num_produtos):
        nome = input("Nome do produto: ")
        preco = float(input("Preço do produto: "))
        validade = input("Data de validade (dd/mm/yyyy): ")
        quantidade = int(input("Quantidade do produto: "))
        produtos.append(Produto(nome, preco, validade, quantidade))

    return produtos

produtos = inserir_produtos()

print("\nEscolha o critério de ordenação:")
print("1. Nome")
print("2. Preço")
print("3. Data de Validade")
print("4. Quantidade")
criterio = int(input("Digite o número do critério escolhido: "))

if criterio == 1:
    produtos_ordenados = ordena_por_nome(produtos)
elif criterio == 2:
    produtos_ordenados = ordena_por_preco(produtos)
elif criterio == 3:
    produtos_ordenados = ordena_por_validade(produtos)
elif criterio == 4:
    produtos_ordenados = ordena_por_quantidade(produtos)
else:
    print("Critério inválido. Ordenando por nome como padrão.")
    produtos_ordenados = ordena_por_nome(produtos)

print("\nProdutos ordenados:")
for produto in produtos_ordenados:
    print(produto)
