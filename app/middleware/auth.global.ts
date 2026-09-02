export default defineNuxtRouteMiddleware((to) => {
  if (import.meta.client) {
    return;
  }

  const authCookie = useCookie("auth");
  const isAuthenticated = authCookie.value === "authenticated";

  // console.log("isAuth ", isAuthenticated, ", to = ", to)

  if (!isAuthenticated && to.path !== "/login") {
    // console.log("Redirected to login !");
    return navigateTo("/login");
  }

  if (isAuthenticated && to.path === "/login") {
    // console.log("redirected to /");
    return navigateTo("/", { replace: true });
  }
});
