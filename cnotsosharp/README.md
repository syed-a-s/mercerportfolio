Compliation and run instructions

------------------
NOTE 
------------------

Rust will give a warning -ignore it
The variable it says is never used is literaly used immediatly after its declarition
The compiler does not know what it is talking about

"Rust is just C but bad" - Mike


-------------------------------------------------------

Each run command will require exactly two numebrs to follow
with a sapce in between them denoted by "_ _"

---------------------------------
Run it all with one bash file:
chmod u+x tester
./tester _ _


------------------------
Individual runs


C#:
mcs composite.cs
mono composite.exe _ _

Rust:
rustc composite.rs
./composite _ _

Go:
go run composite.go _ _

Fortran:
gfortran composite.f95
./a.out _ _

Lisp:
chmod u+x composite.lisp
./composite.lisp _ _


