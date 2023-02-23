# UFL input for the Biharmonic equation
# ==================================
#
# The first step is to define the variational problem at hand. We define
# the variational problem in UFL terms in a separate form file
# :download:`biharmonic.py`.  We begin by defining the finite element::
from basix.ufl_wrapper import create_vector_element
from ufl import (Coefficient, Constant, FiniteElement, FunctionSpace, Mesh, FacetNormal, CellDiameter,
                 TestFunction, TrialFunction, dx, grad, div, avg, dS, jump, inner, triangle)

element = FiniteElement("Lagrange", triangle, 2)

# The first argument to :py:class:`FiniteElement` is the finite element
# family, the second argument specifies the domain, while the third
# argument specifies the polynomial degree. Thus, in this case, our
# element ``element`` consists of first-order, continuous Lagrange basis
# functions on triangles (or in order words, continuous piecewise linear
# polynomials on triangles).
#
# Next, we use this element to initialize the trial and test functions
# (:math:`u` and :math:`v`) and the coefficient functions (:math:`f`)::

coord_element = create_vector_element("Lagrange", "triangle", 1)
mesh = Mesh(coord_element)

V = FunctionSpace(mesh, element)

u = TrialFunction(V)
v = TestFunction(V)
f = Coefficient(V)

# Normal component, mesh size and right-hand side
n = FacetNormal(mesh)
h = CellDiameter(mesh)
h_avg = (h('+') + h('-'))/2

alpha = Constant(mesh)

# Bilinear form
a = inner(div(grad(u)), div(grad(v)))*dx \
  - inner(avg(div(grad(u))), jump(grad(v), n))*dS \
  - inner(jump(grad(u), n), avg(div(grad(v))))*dS \
  + alpha/h_avg*inner(jump(grad(u),n), jump(grad(v),n))*dS

# Linear form
L = f*v*dx
