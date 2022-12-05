#run this file with `python anim.py` from command line
#open the .gif in whatever you usually open them with to check that it worked
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
fig=plt.figure()
#you can put something depending on i here
grid_size = 50
mesh = np.full((grid_size+2,grid_size+2),0.5)
mesh[grid_size+1,:] = np.linspace(100,0,grid_size+2)
mesh[:,0] = np.linspace(0,100,grid_size+2)
mesh[0,:] = 0
mesh[:,grid_size+1] = 0

mesh_new = mesh.copy()

frames=[]
def animate(k,mesh=mesh,grid_size=grid_size): 
    mesh = evolve(k,mesh,grid_size)
    plt.imshow(mesh)

def evolve(nstep,mesh,grid_size):
    step = 0
    mesh_new = mesh.copy()
    while step < nstep:
        for i in range(1,grid_size+1):
            for j in range(1,grid_size+1):
                mesh_new[i,j] = 0.25*(mesh[i-1,j]+mesh[i+1,j]+mesh[i,j-1]+mesh[i,j+1])
                mesh = mesh_new.copy()
        step += 1
        frames.append([plt.imshow(mesh,animated=True)])
    return(mesh)

evolve(1000,mesh,grid_size)
anim = animation.ArtistAnimation(fig,frames,interval=10)
plt.show()
#anim = animation.FuncAnimation(fig,animate,frames=100, interval=10)

# save the animation as an gif
anim.save("animation_example.gif") 
