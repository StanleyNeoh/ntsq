# ntsq (**N**e**t**work **Sq**uisher)

`ntsq` is an installable bash tool to squish your subnets / CIDRs 
to a minimal set.

`ntsq` uses a recursive algorithm to combine and remove redundant CIDRs.
1. If CIDR *A* is a superset of CIDR *B*, we can remove *B*.
2. If CIDR *A* and CIDR *B* are neighbours we can merge them to a single bigger CIDR *C*

By storing the CIDRs in a binary trie, we can perform this combining 
and removal of redundant CIDRs with a post-order traversal of the trie.


## Installation and Setup
You will require a C++ compiler on your machine.

To install it is very simple
1. Clone repository to your machine.
2. `cd` into the repository.
3. Run `sudo make install` to install the binary.

## Examples
Try out some of the examples in `examples/` to see what `ntsq` is about.
1. `cd` into the repository
2. Run `cat examples/example_1.in | ntsq` on bash and witness see how **> 50** CIDRs is squished into just **3** *(results vary with different sets)*

## Uninstallation procedure
To uninstall, simply delete the single binary that was installed 
on your machine.

For example on bash you can simply run the following 
`which ntsq | sudo xargs rm`

## Running tests
To run the test simply run `make test`.