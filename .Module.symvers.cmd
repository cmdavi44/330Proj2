cmd_/home/kerneldev/Documents/330proj2/Module.symvers := sed 's/\.ko$$/\.o/' /home/kerneldev/Documents/330proj2/modules.order | scripts/mod/modpost -m -a  -o /home/kerneldev/Documents/330proj2/Module.symvers -e -i Module.symvers   -T -
