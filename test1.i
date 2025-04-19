[Mesh]
    type = GeneratedMesh
    dim = 2
    nx = 200
    ny = 200  
    xmin = 0.0
    xmax = 1.0
    ymin = 0.0
    ymax = 1.0
[]

[Variables]
    [./c]
        family = LAGRANGE
        order = FIRST
    [../]
  
    [./mu]
        family = LAGRANGE
        order = FIRST
    [../]
[]

[Kernels]
    # C
    [./C1App]
        type = C1
        variable = c
    [../]
    [./C2]
        type = C2
        variable = c
        mu = mu
    [../]
    # mu
    [./M1]
        type = M1
        variable = mu
    [../]
    [./M2]
        type = M2
        variable = mu
        c = c
    [../]
    [./M3]
        type = M3
        variable = mu
        c = c
    [../]

[]

[ICs]
    [./rand_init]
      type = RandomIC
      variable = c
      min = 0.62
      max = 0.64
      seed = 42
    [../]
  
    [./mu_ic]
      type = ConstantIC
      variable = mu
      value = 0.0
    [../]
[]
  


[BCs]
    [./c_flux]
      type = NeumannBC
      variable = c
      boundary = 'left right top bottom'
      value = 0.0
    [../]
    [./mu_flux]
      type = NeumannBC
      variable = mu
      boundary = 'left right top bottom'
      value = 0.0
    [../]
[]

[Executioner]
    type = Transient
    solve_type = PJFNK
    dt = 1e-6
    dtmin = 1e-10
    dtmax = 1e-2
    start_time = 0
    end_time = 0.01

    automatic_scaling = true

    nl_rel_tol = 1e-6
    nl_abs_tol = 1e-8
    nl_max_its = 60
    l_max_its = 200

    petsc_options_iname = '-ksp_type -pc_type -pc_factor_mat_solver_type'
    petsc_options_value = 'gmres lu mumps'
[]


[Outputs]
    [./exodus]
      type = Exodus
      interval = 10     
      file_base = simulation     
      execute_on = 'initial timestep_end' 
    [../]
    [./checkpoint]
        type = Checkpoint
        time_step_interval = 20
        num_files = 2   
    [../]
[]