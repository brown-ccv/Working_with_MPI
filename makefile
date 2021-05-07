EXECS=send_data
MPICC?=mpicc

all: ${EXECS}

${EXECS}: ${EXECS}.c
	${MPICC} -o $@ $<

clean:
	rm ${EXECS}
