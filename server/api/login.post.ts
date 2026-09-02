export default defineEventHandler(async (event) => {
  const body = await readBody(event);

  if (body.password === "popo5a") {
    setCookie(event, "auth", "authenticated", {
      path: "/",
      maxAge: 60 * 60 * 24 * 7,
      httpOnly: true,
      secure: false,
      sameSite: "lax",
    });
    return { success: true };
  }

  throw createError({
    statusCode: 401,
    statusMessage: "Mot de passe incorrect",
  });
});
