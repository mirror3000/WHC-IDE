/**
 * File auto generated by WHC-IDE.
 *
 * Task name: `TASKNAME`
 * Date: `DATE`
 *
 * This file provides the entry point for your task.
 * The IDE will automatically provide the arguments at run-time.
 * The programmer will determine how the task operates when given the
 * arguments.
 *
 *===============================================
 *Format of the arguments that are passed by WHC.
 *===============================================
 * argc - the number of arguments the task has received;
 * argv - the arguments vector, stored as char strings;
 *        argv has a length of argc;
 *        argv[0]        - name of the executable;
 *        argv[1]        - "-in". Specifies that the next arguments
 *                         will be input file-names;
`EXPAND' *        argv[`ARGNO4`] - "-out". Specifies that the next argument
 *                         will be the output file-name. Each task
 *                         can only have one output file;
 *        argv[`ARGNO3`] - output file-name;
 *        argv[`ARGNO2`] - "-dev". Specifies that the next argument
 *                         will be the device index. The device index
 *                         selects the device that will run the task;
 *        argv[`ARGNO1`] - device index (starting at 0).
 */


int main(int argc, char *argv[]) {
	
	if(argc < `ARGNO`) {
		printf("Usage: ./whc -in in1.txt `INFILES`-out out.txt -dev 0");
	}
	return 0;
}
