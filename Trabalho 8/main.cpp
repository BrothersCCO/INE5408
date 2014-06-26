#include <cstdlib>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sys/time.h>

#include "avl_tree.h"
#include "red_black_tree.h"
#include "list.h"

class logradouro {  
public:
  logradouro() {}

  logradouro(std::string nome, int cep) {
    _nome = nome;
    _cep = cep;
  }
  
  bool operator<(const logradouro& rhs) const {
    return _nome < rhs._nome;
  }
  
  bool operator>(const logradouro& rhs) const {
    return rhs < *this;
  }
  
  logradouro& operator=(const logradouro& rhs) {
    _nome = rhs._nome;
    _cep = rhs._cep;
    return *this;
  }
  
  std::string nome() const {
    return _nome;
  }
  
  int cep() const {
    return _cep;
  }

private:  
  std::string _nome;
  int _cep;
};

long diff(timeval inicio, timeval fim) {
	long diferenca, segundos, usegundos;

	segundos = fim.tv_sec - inicio.tv_sec;
	usegundos = fim.tv_usec - inicio.tv_usec;

	diferenca = segundos * 1000000 + usegundos;
	return diferenca;
}

timeval tempo() {
	timeval tempo;
	gettimeofday(&tempo, NULL);
	return tempo;
}

int main(int argc, char** argv) {
	using std::cin;
  using std::cout;
  using std::endl;
  using std::ifstream;
  using std::numeric_limits;
  using std::ofstream;
  using std::streamsize;
  using std::string;
  
  ifstream input;
  ofstream data, data2, conf;
  
  if (argc != 3) {
    cout << "Como usar: " << argv[0] << " <fonte> <destino>" << endl << endl
      << "Exemplo: " << argv[0] << " sp.dat arvere.out" << endl;   
      exit(1);
  }
  
  input.open(argv[1]);
	data.open(argv[2]);
 
  if (!input.is_open()) {
    cout << "Não foi possível abrir o arquivo fonte: " << argv[1] << endl;
    exit(1);
  }
  avl_tree<logradouro> avl;
  red_black_tree<logradouro> rb;
	tree<logradouro>* tree = &avl,
                  * tree2 = &rb;

	char tree_t = '0';
	cout << "Que árvore deseja utilizar?" << endl
	  << "1) AVL" << endl
	  << "2) Red-Black" << endl
	  << "3) Ambas" << endl;
	while (tree_t != '1' && tree_t != '2' && tree_t != '3') {
		cin >> tree_t;
    if (tree_t == '2')
	    tree = &rb;
    else if (tree_t == '3') {
  		string aux(argv[2]);
  		aux += "2";
  		data2.open(aux.c_str());
  	}
		else if (tree_t != '1')
			cout << "Não entendi. Digite '1' para AVL, '2' Red-Black ou '3' para ambas ";
  	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
  
  string line;
  string nome;
  int cep;
  
  int cont = 0;
  timeval inicio, fim;
  
  while (!input.eof()) {
    std::getline(input, line);
    
    nome = line.substr(0, line.find_first_of("|"));
    cep = atoi(line.substr(line.find_first_of("|") + 1, line.size()).c_str());    
    logradouro log(nome, cep);
    
    inicio = tempo();    
    tree->insert(log);
    fim = tempo();
    data << ++cont << ' ' << diff(inicio, fim) << endl;
    
    if (tree_t == '3') {
      inicio = tempo();    
      tree2->insert(log);
      fim = tempo();
      data2 << ++cont << ' ' << diff(inicio, fim) << endl;
    }
  }
 
	char res = 'n';
	cout << "Deseja mostrar os nomes em ordem alfabética? (y/n) ";
	while (res != 'y') {
		cin >> res;
		if (res == 'y') {
			list<logradouro> arr = tree->in_order();
		  for (list<logradouro>::const_iterator it = arr.cbegin(); it != arr.cend(); ++it)
				cout << it->nome() << endl;
		}
		else if (res == 'n')
			break;
		else
			cout << "Não entendi. Digite 'y' para sim ou 'n' para não ";
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	res = 'n';
	cout << "Deseja gerar o gráfico de tempos através do gnuplot? (y/n) ";
	while (res != 'y') {
		cin >> res;
		if (res == 'y') {
		  string tree_name = tree_t == '2' ? "Red-Black" : "AVL";
		  string title = tree_t == '3' ? "AVL e Red-Black" : tree_name;
			conf.open(".conf");
			conf << "set title \"Diferença entre tempos de inserção - " << title << "\"" << endl
				<< "set xlabel \"Quantidade de nós\"" << endl
				<< "set ylabel \"microssegundos\"" << endl
				<< "plot \"" << argv[2] << "\" title \"árvore " << tree_name << "\" with lines,\\" << endl;
				if (tree_t == '3') {
				  conf << "\"" << argv[2] << "2\" title \"árvore Red-Black\" with lines" << endl;
				}
		  std::system("gnuplot -persist .conf && rm  .conf");
		}
		else if (res == 'n')
			break;
		else
			cout << "Não entendi. Digite 'y' para sim ou 'n' para não ";
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
  
  return 0;
}
