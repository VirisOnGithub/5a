export default defineNuxtRouteMiddleware((to) => {

  if (to.path === '/login') {
      return
  }

  const authCookie = useCookie('auth')

  if (authCookie.value !== 'authenticated') {
    return navigateTo('/login')
  }
})
