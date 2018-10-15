using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string>mp;
		vector<vector<string>> res;
		for (auto w : wordList) mp.insert(w);
		vector<string> path;
		vector<string> visited;
		queue<vector<string>>q;
		q.push({ beginWord });
		int minval = INT_MAX;
		while (!q.empty()) {
			int cnt = q.size();
			for (int i = 0; i < cnt; i++) {
				path = q.front(), q.pop();
				if (path.size() > minval) {
					return res;
				}
				if (path.back() == endWord) {
					minval = path.size();
					res.push_back(path);
					continue;
				}
				add(visited, path, q, mp);
			}
			for (auto w : visited) mp.erase(w);
			visited.clear();
		}
		return res;
	}
	void add(vector<string>&visited, vector<string> &path, queue<vector<string>>&q, unordered_set<string>&mp) {
		string now = path.back();
		for (int j = 0; j < now.size(); j++) {
			char c = now[j];
			for (int i = 0; i < 26; i++) {
				now[j] = 'a' + i;
				if (mp.find(now) != mp.end()) {
					vector<string>new_path(path);
					new_path.push_back(now);
					q.push(new_path);
					visited.push_back(now);
				}
			}
			now[j] = c;
		}
	}
};






int main() {
	Solution a;
	//string beginWord = "charge";
	//string endWord = "comedo";
	//vector<string> wordList = { "shanny", "shinny", "whinny", "whiney", "shiver", "sharer", "scarer", "scaler", "render", "fluxes", "teases", "starks", "clinks", "messrs", "crewed", "donner", "blurts", "bettye", "powell", "castes", "hackee", "hackle", "heckle", "deckle", "decile", "defile", "define", "refine", "repine", "rapine", "ravine", "raving", "roving", "chased", "roping", "coping", "coming", "homing", "pointy", "hominy", "homily", "homely", "comely", "comedy", "comedo", "vagues", "crocus", "spiked", "bobbed", "dourer", "smells", "feared", "wooden", "stings", "loafer", "pleads", "gaiter", "meeter", "denser", "bather", "deaves", "wetted", "pleats", "cadger", "curbed", "grover", "hinged", "budget", "gables", "larked", "flunks", "fibbed", "bricks", "bowell", "yonder", "grimes", "clewed", "triads", "legion", "lacier", "ridden", "bogied", "camper", "damien", "spokes", "flecks", "goosed", "snorer", "choked", "choler", "leakey", "vagued", "flumes", "scanty", "bugger", "tablet", "nilled", "julies", "roomed", "ridges", "snared", "singes", "slicks", "toiled", "verged", "shitty", "clicks", "farmed", "stunts", "dowsed", "brisks", "skunks", "linens", "hammer", "naiver", "duster", "elates", "kooked", "whacky", "mather", "loomed", "soured", "mosses", "keeled", "drains", "drafty", "cricks", "glower", "brayed", "jester", "mender", "burros", "arises", "barker", "father", "creaks", "prayed", "bulges", "heaped", "called", "volley", "girted", "forded", "huffed", "bergen", "grated", "douses", "jagger", "grovel", "lashes", "creeds", "bonier", "snacks", "powder", "curled", "milker", "posers", "ribbed", "tracts", "stoked", "russel", "bummer", "cusses", "gouged", "nailed", "lobbed", "novels", "stands", "caches", "swanks", "jutted", "zinged", "wigged", "lunges", "divers", "cranny", "pinter", "guides", "tigers", "traces", "berber", "purges", "hoaxer", "either", "bribed", "camped", "funked", "creaky", "noises", "paused", "splits", "morrow", "faults", "ladies", "dinged", "smoker", "calved", "deters", "kicker", "wisher", "ballad", "filled", "fobbed", "tucker", "steams", "rubber", "staled", "chived", "warred", "draped", "curfew", "chafed", "washer", "tombed", "basket", "limned", "rapped", "swills", "gashed", "loaner", "settee", "layers", "bootee", "rioted", "prance", "sharps", "wigner", "ranted", "hanker", "leaden", "groped", "dalian", "robbed", "peeled", "larder", "spoofs", "pushed", "hallie", "maiden", "waller", "pashas", "grains", "pinked", "lodged", "zipper", "sneers", "bootie", "drives", "former", "deepen", "carboy", "snouts", "fained", "wilmer", "trance", "bugles", "chimps", "deeper", "bolder", "cupped", "mauser", "pagers", "proven", "teaser", "plucky", "curved", "shoots", "barged", "mantes", "reefer", "coater", "clotho", "wanner", "likens", "swamis", "troyes", "breton", "fences", "pastas", "quirky", "boiler", "canoes", "looted", "caries", "stride", "adorns", "dwells", "hatred", "cloths", "rotted", "spooks", "canyon", "lances", "denied", "beefed", "diaper", "wiener", "rifled", "leader", "ousted", "sprays", "ridged", "mousey", "darken", "guiled", "gasses", "suited", "drools", "bloody", "murals", "lassie", "babied", "fitter", "lessee", "chiles", "wrongs", "malian", "leaves", "redder", "funnel", "broths", "gushes", "grants", "doyens", "simmer", "locked", "spoors", "berger", "landed", "mosley", "scorns", "whiten", "hurled", "routed", "careen", "chorus", "chasms", "hopped", "cadged", "kicked", "slewed", "shrewd", "mauled", "saucer", "jested", "shriek", "giblet", "gnarls", "foaled", "roughs", "copses", "sacked", "blends", "slurps", "cashew", "grades", "cramps", "radius", "tamped", "truths", "cleans", "creams", "manner", "crimps", "hauled", "cheery", "shells", "asters", "scalps", "quotas", "clears", "clover", "weeder", "homers", "pelted", "hugged", "marked", "moaned", "steely", "jagged", "glades", "goshes", "masked", "ringer", "eloped", "vortex", "gender", "spotty", "harken", "hasten", "smiths", "mulled", "specks", "smiles", "vainer", "patted", "harden", "nicked", "dooley", "begged", "belief", "bushel", "rivers", "sealed", "neuter", "legged", "garter", "freaks", "server", "crimea", "tossed", "wilted", "cheers", "slides", "cowley", "snotty", "willed", "bowled", "tortes", "pranks", "yelped", "slaved", "silver", "swords", "miners", "fairer", "trills", "salted", "copsed", "crusts", "hogged", "seemed", "revert", "gusted", "pixies", "tamika", "franks", "crowed", "rocked", "fisher", "sheers", "pushes", "drifts", "scouts", "sables", "sallie", "shiner", "coupes", "napped", "drowse", "traced", "scenes", "brakes", "steele", "beater", "buries", "turned", "luther", "bowers", "lofted", "blazer", "serves", "cagney", "hansel", "talker", "warmed", "flirts", "braced", "yukked", "milken", "forged", "dodder", "strafe", "blurbs", "snorts", "jetted", "picket", "pistil", "valved", "pewter", "crawls", "strews", "railed", "clunks", "smiled", "dealer", "cussed", "hocked", "spited", "cowers", "strobe", "donned", "brawls", "minxes", "philby", "gavels", "renter", "losses", "packet", "defied", "hazier", "twines", "balled", "gaoled", "esther", "narrow", "soused", "crispy", "souped", "corned", "cooley", "rioter", "talley", "keaton", "rocker", "spades", "billie", "mattel", "billet", "horton", "navels", "sander", "stoker", "winded", "wilder", "cloyed", "blazed", "itched", "docked", "greene", "boozed", "ticket", "temped", "capons", "bravos", "rinded", "brandi", "massed", "sobbed", "shapes", "yippee", "script", "lesion", "mallet", "seabed", "medals", "series", "phases", "grower", "vertex", "dented", "tushed", "barron", "toffee", "bushes", "mouser", "zenger", "quaked", "marley", "surfed", "harmed", "mormon", "flints", "shamed", "forgot", "jailor", "boater", "sparer", "shards", "master", "pistol", "tooted", "banned", "drover", "spices", "gobbed", "corals", "chucks", "kitten", "whales", "nickel", "scrape", "hosted", "hences", "morays", "stomps", "marcel", "hummed", "wonder", "stoves", "distil", "coffer", "quaker", "curler", "nurses", "cabbed", "jigger", "grails", "manges", "larger", "zipped", "rovers", "stints", "nudges", "marlin", "exuded", "storey", "pester", "longer", "creeps", "meaner", "wallop", "dewier", "rivera", "drones", "valued", "bugled", "swards", "cortes", "charts", "benson", "wreaks", "glares", "levels", "smithy", "slater", "suites", "paired", "fetter", "rutted", "levied", "menses", "wither", "woolly", "weeded", "planed", "censer", "tested", "pulled", "hitter", "slicer", "tartar", "chunky", "whirrs", "mewled", "astern", "walden", "hilton", "cached", "geller", "dolled", "chores", "sorter", "soothe", "reused", "clumps", "fueled", "hurler", "helled", "packed", "ripped", "tanned", "binder", "flames", "teased", "punker", "jerked", "cannon", "joists", "whited", "sagged", "heaven", "hansen", "grayer", "turfed", "cranks", "stater", "bunted", "horsey", "shakes", "brands", "faints", "barber", "gorged", "creamy", "mowers", "scrams", "gashes", "knacks", "aeries", "sticks", "altars", "hostel", "pumped", "reeves", "litter", "hoaxed", "mushed", "guided", "ripper", "bought", "gelled", "ranker", "jennie", "blares", "saloon", "bomber", "mollie", "scoops", "coolie", "hollis", "shrunk", "tattle", "sensed", "gasket", "dodoes", "mapped", "strips", "dodges", "sailed", "talked", "sorted", "lodges", "livest", "pastel", "ladles", "graded", "thrice", "thales", "sagger", "mellon", "ganged", "maroon", "fluked", "raised", "nannie", "dearer", "lither", "triked", "dorset", "clamps", "lonnie", "spates", "larded", "condor", "sinker", "narced", "quaver", "atones", "farted", "elopes", "winger", "mottle", "loaned", "smears", "joanne", "boozes", "waster", "digger", "swoops", "smokey", "nation", "drivel", "ceased", "miffed", "faiths", "pisses", "frames", "fooled", "milled", "dither", "crazed", "darryl", "mulder", "posses", "sumter", "weasel", "pedals", "brawny", "charge", "welted", "spanks", "sallow", "joined", "shaker", "blocks", "mattie", "swirls", "driver", "belles", "chomps", "blower", "roared", "ratted", "hailed", "taunts", "steamy", "parrot", "deafer", "chewed", "spaces", "cuffed", "molded", "winked", "runnel", "hollow", "fluted", "bedded", "crepes", "stakes", "vested", "parley", "burton", "loiter", "massey", "carnap", "closed", "bailed", "milder", "heists", "morale", "putter", "snyder", "damion", "conned", "little", "pooped", "ticced", "cocked", "halves", "wishes", "francs", "goblet", "carlin", "pecked", "julius", "raster", "shocks", "dawned", "loosen", "swears", "buried", "peters", "treats", "noshed", "hedges", "trumps", "rabies", "ronnie", "forces", "ticked", "bodies", "proved", "dadoes", "halved", "warner", "divest", "thumbs", "fettle", "ponies", "testis", "ranked", "clouts", "slates", "tauted", "stools", "dodged", "chancy", "trawls", "things", "sorrow", "levies", "glides", "battle", "sauced", "doomed", "seller", "strove", "ballet", "bumper", "gooses", "foiled", "plowed", "glints", "chanel", "petals", "darted", "seared", "trunks", "hatter", "yokels", "vanned", "tweedy", "rubles", "crones", "nettie", "roofed", "dusted", "dicker", "fakers", "rusted", "bedder", "darrin", "bigger", "baylor", "crocks", "niches", "tented", "cashed", "splats", "quoted", "soloed", "tessie", "stiles", "bearer", "hissed", "soiled", "adored", "bowery", "snakes", "wagers", "rafter", "crests", "plaids", "cordon", "listed", "lawson", "scared", "brazos", "horded", "greens", "marred", "mushes", "hooper", "halter", "ration", "calked", "erodes", "plumed", "mummer", "pinged", "curios", "slated", "ranter", "pillow", "frills", "whaled", "bathos", "madden", "totted", "reamed", "bellow", "golfer", "seaman", "barred", "merger", "hipped", "silken", "hastes", "strays", "slinks", "hooted", "convex", "singed", "leased", "bummed", "leaner", "molted", "naught", "caters", "tidied", "forges", "sealer" };
	//vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	string beginWord = "a";
	string endWord = "c";
	vector<string> wordList = { "a","b","c" };
	a.findLadders(beginWord, endWord, wordList);
	return 0;
}
