<script setup lang="ts">
const route = useRoute();
</script>

<template>
    <div>
        {{ route.query.test }}
    </div>
</template>
