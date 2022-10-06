import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.regex.*;

public class RegexExtractor {
    private static boolean flagSort = false;
    private static boolean flagDistinct = false;
    private static boolean flagTrim = false;
    private static boolean flagRemoveParenthesis = false;

    public static void main(String[] args) {
        int argsLengthOrg = args.length;
        int argsLength = args.length;

        List<String> argsList = new ArrayList<>(Arrays.asList(args));
        ListIterator<String> iter = argsList.listIterator();
        while (iter.hasNext()) {
            String arg = iter.next();
            if (arg.startsWith("-")) {
                switch (arg) {
                    case "-sort":
                    case "-s":
                        System.out.println("SORT ON");
                        flagSort = true;
                        break;
                    case "-distinct":
                    case "-d":
                        System.out.println("DISTINCT ON");
                        flagSort = true;
                        break;
                    case "-trim":
                    case "-t":
                        System.out.println("TRIM ON");
                        flagTrim = true;
                        break;
                    case "-removeParenthesis":
                    case "-rp":
                        System.out.println("REMOVE PARENTHESIS ON");
                        flagRemoveParenthesis = true;
                        break;

                    default:
                        System.out.println("Invalid option: " + arg);
                        break;
                }
                iter.remove();
            }
        }

        if (argsList.size() != 1) {
            System.out.println("You must call like 'java RegexExtractor [srcFilename] [OPTIONS]' !");
            return;
        }

        System.out.println("Enter the pattern: ");

        Scanner scanner = new Scanner(System.in);

        String srcFile = argsList.get(0);
        String regex = scanner.nextLine();

        try {
            // read file
            File file = new File(srcFile);
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            Collection<String> matchList;
            String line;

            // select data structure by distincting flag
            if (flagDistinct) {
                if (flagSort) {
                    matchList = new TreeSet<String>();
                } else {
                    matchList = new HashSet<String>();
                }
            } else {
                matchList = new LinkedList<String>();
            }

            // result file
            File resFile = new File("result.txt");
            BufferedWriter bw = new BufferedWriter(new FileWriter(resFile));

            // regex pattern
            Pattern p = Pattern.compile(regex);

            while ((line = br.readLine()) != null) {
                Matcher m = p.matcher(line);
                while (m.find()) {
                    String match = m.group();
                    if (flagTrim) {
                        match = match.trim();
                    }
                    if (flagRemoveParenthesis) {
                        match = match.replaceAll("\\(.*\\", "");
                    }
                    matchList.add(match);
                }
            }

            if (!flagDistinct && flagSort) {
                // sort when sorting flag is on
                Collections.sort((List<String>) matchList);
            }

            for (String match : matchList) {
                // print to file
                bw.write(match + "\n");
            }
            bw.flush();

            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}