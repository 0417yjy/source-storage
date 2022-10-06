package Java;

import java.util.regex.*;
import java.util.Properties;
import java.io.*;
import java.nio.charset.*;

public class TextDivider {
    private static String[] splitFileNameExt(String canonicalPath) {
        int idx;
        String fileName = canonicalPath;
        String[] res = new String[2];
        String ext;

        if (fileName == null || (idx = fileName.lastIndexOf(".")) == -1)
            return null;

        if (fileName.substring(idx + 1).isEmpty()) {
            ext = null;
        } else {
            ext = "." + fileName.substring(idx + 1);
        }

        res[0] = fileName.substring(0, idx);
        res[1] = ext;
        return res;
    }

    private static boolean isIncluded(String[] stdCol, String[] data, int colCnt) {
        for (int i = 0; i < colCnt; i++) {
            if (!stdCol[i].equals(data[i])) {
                return false;
            }
        }

        return true;
    }

    private static String makeDivFilename(String src, String[] cols) {
        StringBuilder sb = new StringBuilder(src);
        for (int i = 0; i < cols.length; i++) {
            sb.append("_" + cols[i]);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        String srcFile = null;
        String del = null;
        int colCnt = 0;

        if (args.length != 3) {
            System.out.println("Calling format is invalid. get Parameter from config.ini");
            System.out.println(
                    "To set parameter manually, 'java TextDivider [srcFilename] [delimiter] [COLUMNS_COUNT]'!");

            // get parameters from config file
            try {
                Properties p = new Properties();

                p.load(new FileInputStream("config.ini"));

                srcFile = p.getProperty("srcFile");
                del = p.getProperty("del");
                colCnt = Integer.parseInt(p.getProperty("colCnt"));
            } catch (Exception e) {
                System.out.println(e);
                return;
            }
        } else {
            srcFile = args[0];
            del = args[1];
            colCnt = Integer.parseInt(args[2]);
        }

        System.out.println("srcFile: " + srcFile);
        System.out.println("del: " + del);
        System.out.println("colCnt: " + colCnt);

        String[] srcFileArr = splitFileNameExt(srcFile);

        try {
            // read file
            File f = new File(srcFile);
            FileInputStream is = new FileInputStream(f);
            BufferedReader br = new BufferedReader(new InputStreamReader(is, Charset.forname("UTF-16")));
            String line = null;
            String title = null;
            String[] stdColValArr = null;
            File resFile = null;
            BufferedWriter bw = null;

            // make dir if not exists
            new File("res").mkdir();

            while ((line = br.readLine()) != null) {
                if (title == null) {
                    title = line; // get first line as title
                    continue;
                }

                String[] data = line.split(Pattern.quote(del));

                if (stdColValArr == null || !isIncluded(stdColValArr, data, colCnt)) {
                    // close and save current file
                    if (resFile != null && bw != null) {
                        bw.flush();
                        bw.close();
                    }

                    // overwrite stdColValArr
                    stdColValArr = new String[colCnt];
                    for (int i = 0; i < colCnt; i++) {
                        stdColValArr[i] = data[i];
                        System.out.println(stdColValArr[i] + del);
                    }
                    System.out.println();

                    // make a new file
                    resFile = new File("res\\" + makeDivFilename(srcFileArr[0], stdColValArr) + srcFileArr[1]);
                    bw = new BufferedWriter(new FileWriter(resFile));
                    bw.write(title + "\n");
                }

                // print to file
                bw.write(line + "\n");
            }

            // close and save the last file
            bw.flush();
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
