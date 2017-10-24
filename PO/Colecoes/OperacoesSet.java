import java.util.HashSet;
public class OperacoesSet
{
 public static void main(String[] args)
 {
	HashSet<String> solteiros = new HashSet<String>();
	solteiros.add("Tom");
	solteiros.add("Larry");
	HashSet<String> casados = new HashSet<String>();
	casados.add("Nathan");
	casados.add("Jeffrey");
	casados.add("Randal");
	casados.add("Sriram");
	HashSet<String> tenistas = new HashSet<String>();
	tenistas.add("Tom");
	tenistas.add("Jeffrey");
	tenistas.add("Larry");
	HashSet<String> nadadores = new HashSet<String>();
	nadadores.add("Nathan");
	nadadores.add("Sriram");
	nadadores.add("Tom");
	// Todos os autores
	HashSet<String> todos = new HashSet<String>(casados);
	todos.addAll(solteiros);
	// [Nathan, Tom, Jeffrey, Larry, Randal, Sriram]
	// Nadadores e tenistas
	HashSet<String> nadadoresETenistas = new HashSet<String>(nadadores);
	nadadoresETenistas.retainAll(tenistas); // [Tom]
	// Tenistas e casados
	HashSet<String> tenistasCasados = new HashSet<String>(tenistas);
	tenistasCasados.retainAll(casados);
	System.out.println(tenistasCasados); // [Jeffrey]
	// Tenistas ou casados
	HashSet<String> tenistasOuCasados = new HashSet<String>(tenistas);
	tenistasOuCasados.addAll(casados);
	System.out.println(tenistasOuCasados);
	// [Nathan, Tom, Jeffrey, Larry, Randal, Sriram]
	// Casados mas não atletas
	HashSet<String> casadosMasNãoAtletas = new HashSet<String>(casados);
	casadosMasNãoAtletas.removeAll(tenistas);
	casadosMasNãoAtletas.removeAll(nadadores); // [Randal]
	// Todo nadador é tenista ?
	System.out.println(tenistas.containsAll(nadadores)); // false
	// Todo solteiro é tenista ?
	System.out.println(tenistas.containsAll(solteiros)); // true
 }
}